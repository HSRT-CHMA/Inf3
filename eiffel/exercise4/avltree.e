note
	description: "Summary description for {AVLTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	AVLTREE[G->COMPARABLE]

inherit
	GENERICTREE[G]
	redefine insert,delete,has,attached_node end

create
	make

feature {NONE} -- Initialization / Constructor ; gets the value that serves as root-value

	make(tree_value : G)
		do
			print("%N A new AVL Tree has been created")
			empty := TRUE
			rebalance := FALSE
			create root.make(tree_value, Void)
		end

feature --Access

	rebalance: BOOLEAN

feature -- Override of insert
--insers the new value
	insert(new_value: T)
		local
			new_node: NODE[T]
		do
			create new_node.make (new_value)

			if get_empty then
				root:= new_node
				empty:= false
			else
				root := insertRec(attached_node(root), new_node)
			end
		end

feature -- insert Recursiv Method
	insertRec(current_node: AVL_NODE[T] new_node: AVL_NODE[T]) : AVL_NODE[T]
		local
			return: AVL_NODE[T]
			tmp_rotate: AVL_NODE[T]
		do
			return := current_node
			if new_node.get_value.three_way_comparison(current_node.get_value) = 1 then
				if current_node.get_right = void then
					current_node.set_right(new_node)
					new_node.set_parent(current_node)
					current_node.set_balance(current_node.get_balance+1)
					rebalance := current_node.get_balance >= 1
					return := current_node
				else

					current_node.set_right(insertRec(attached_node(current_node.get_right), new_node))
					if rebalance then
						if current_node.get_balance = -1 then
							current_node.set_balance(0)
							rebalance := FALSE
							return := current_node
						elseif current_node.get_balance = 0 then
							current_node.set_balance(1)
							return := current_node
						elseif current_node.get_balance = 1 then
							rebalance := FALSE
							tmp_rotate := attached_node(current_node.get_right)
							if tmp_rotate /= void then
								if tmp_rotate.get_balance = 1 then
									return := rotate_right(current_node)
								else
									return := rotate_double_right_left(current_node)
								end
							end
						end
					else
						return := current_node
					end
				end
			else
				if current_node.get_left = void then
					current_node.set_left(new_node)
					new_node.set_parent(current_node)
					current_node.set_balance(current_node.get_balance-1)
					rebalance := current_node.get_balance <= -1
					return := current_node
				else
				 	current_node.set_left(insertRec(attached_node(current_node.get_left), new_node))
					if rebalance then
						if current_node.get_balance = 1 then
							current_node.set_balance(0)
							rebalance := FALSE
							return := current_node
						elseif current_node.get_balance = 0 then
							current_node.set_balance(-1)
							return := current_node
						elseif current_node.get_balance = -1 then
							rebalance := FALSE
							tmp_rotate := attached_node(current_node.get_left)
							if tmp_rotate.get_balance = -1 then
								return := rotate_left(current_node)
							else
								return := rotate_double_left_right(current_node)
							end
						end
					else
						return := current_node
					end
				end
			end
			Result := return
		end

feature -- Override of delete

	delete(to_delete : G)
		do
			Precursor(to_delete)
		end

feature -- Override of has

	has(value : G): BOOLEAN
		do
			Result := Precursor(value)
		end

feature --check Attach

	attached_node(d_node: detachable NODE[T]): attached NODE[T]
	--returns an attached node
		do
			Result:= Precursor(d_node)
		end


feature {NONE} -- AVL
	--the rotations balance the tree
	rotate_left(b: AVL_NODE[T]): AVL_NODE[T]
		local
			tmp: detachable AVL_NODE[T]
		do
			tmp := b.get_left
			tmp := attached_node(tmp)
			b.set_left(tmp.get_right)
			tmp.set_right(b)
			b.set_balance(0)
			tmp.set_balance(0)

			Result := tmp
		end

	rotate_right(b: AVL_NODE[T]): AVL_NODE[T]
		local
			tmp: detachable AVL_NODE[T]
		do
			tmp := b.get_right
			tmp := attached_node(tmp)
			b.set_right(tmp.get_left)
			tmp.set_left(b)
			b.set_balance(0)
			tmp.set_balance(0)

			Result := tmp
		end

	rotate_double_left_right(c: AVL_NODE[T]): AVL_NODE[T]
		local
			a: detachable AVL_NODE[T]
			b: detachable AVL_NODE[T]
		do
			a := c.get_left
			a := attached_node(a)
			b := a.get_right
			b := attached_node(b)
			a.set_right(b.get_left)
			b.set_left(a)
			c.set_left(b.get_right)
			b.set_right(c)
			if b.get_balance = -1 then
				c.set_balance(1)
			else
				c.set_balance(0)
			end

			if b.get_balance = 1 then
				a.set_balance(-1)
			else
				a.set_balance(0)
			end

			b.set_balance(0)

			Result := b
		end

	rotate_double_right_left(c: AVL_NODE[T]): AVL_NODE[T]
		local
			a: detachable AVL_NODE[T]
			b: detachable AVL_NODE[T]
		do
			a := c.get_right

			a := attached_node(a)
			b := a.get_left

			b := attached_node(b)
			a.set_left(b.get_right)
			b.set_right(a)
			c.set_right(b.get_left)
			b.set_left(c)
			if b.get_balance = -1 then
				c.set_balance(1)
			else
				c.set_balance(0)
			end

			if b.get_balance = 1 then
				a.set_balance(-1)
			else
				a.set_balance(0)
			end

			b.set_balance(0)

			Result := b
		end

end -- Class end


