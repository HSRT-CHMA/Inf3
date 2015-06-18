note
	description: "Summary description for {GENERIC_TREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class GENERICTREE[G->COMPARABLE]
-- Generic Tree Class giving methods to other generic trees
inherit
	MAINTREE[G]
	redefine insert, delete, has end

feature {NONE} --Attributes

	root: detachable NODE[G]
	empty: BOOLEAN

feature --Getters

	get_root: NODE[G]
					--returns root
		require
			tree_not_empty: not get_empty
		do
			Result:= attached_node(root)
		ensure
			res_attached: Result/=void
			is_root: Result.get_parent = void
		end

	get_empty: BOOLEAN
					--returns true if tree is empty
		do
			Result:= empty
		end

	get_smallest: NODE[G]
					--returns smallest value of tree
		require
			tree_not_empty: not get_empty
		local
			tmp_node: attached NODE[G]
		do
			from
				tmp_node:= get_root
			until
				tmp_node.get_left = void
			loop
				tmp_node:= attached_node(tmp_node.get_left)
			end
			Result:= tmp_node
		ensure
			res_attached: Result/=void
			is_smallest: Result.get_left=void
		end

	get_biggest: NODE[G]
					--returns biggest value of tree
		require
			tree_not_empty: not get_empty
		local
			tmp_node: attached NODE[G]
		do
			from
				tmp_node:= get_root
			until
				tmp_node.get_right=void
			loop
				tmp_node:= attached_node(tmp_node.get_right)
			end
			Result:= tmp_node
		ensure
			res_attached: Result/=void
			is_biggest: Result.get_right=void
		end


feature --routines

	insert (new_value: G)
					--adds value to binary tree
		local
			new_node: NODE[G]
			tmp_node: NODE[G]
		do
			create new_node.make (new_value,Void)

			if get_empty then
				root:= new_node
				empty:= false
			else
				from --begin from here, initialize beginer node (root)
					tmp_node:= attached_node(root)
				until --loop goes until the boolean gives true
					(tmp_node.get_value.three_way_comparison(new_value) = 1 and tmp_node.get_left = void) or -- tmp_node.get_value > new_value
					(tmp_node.get_value.three_way_comparison(new_value) = -1 and tmp_node.get_right = void)  -- tmp_node.get_value < new_value
				loop --goes through tree to find suitable end of tree to add node
					if (tmp_node.get_value.three_way_comparison(new_value) = 1) then --tmp_node.get_value > new_value
						tmp_node:= attached_node(tmp_node.get_left)
					else
						tmp_node:= attached_node(tmp_node.get_right)
					end
				end

				if new_value.three_way_comparison(tmp_node.get_value) = 1 or
				  	new_value.three_way_comparison(tmp_node.get_value) = 0 then --new_value >= tmp_node.get_value
					tmp_node.set_right (new_node)
					new_node.set_parent (tmp_node)
				else
					tmp_node.set_left (new_node)
					new_node.set_parent (tmp_node)
				end
			end
	end


	has(value:G): BOOLEAN
					--searches for explizit value in tree, returns true if found
		local
			tmp_node: detachable NODE[G]
			in_tree: BOOLEAN
		do
			in_tree:= false
			from
				tmp_node:= get_root
			until
				in_tree or (tmp_node=void)
			loop
				if tmp_node.get_value.three_way_comparison(value) = 0 then -- tmp_node.get_value = value
					in_tree:= true
				elseif tmp_node.get_value.three_way_comparison(value) = 1 then -- tmp_node.get_value > value
					tmp_node:= tmp_node.get_left
				else
					tmp_node:= tmp_node.get_right
				end
			end
			Result:= in_tree
		end


		delete(to_delete: G)
						--deletes all nodes with the explizit value in tree
			local
				tmp_node: NODE[G]
			do
				from
					tmp_node:= get_root
				until
					not has(to_delete)
				loop
					if tmp_node.get_value.three_way_comparison(to_delete) = 0 then -- tmp_node.get_value = to_delete
						delete_node(tmp_node)
						tmp_node:= attached_node(get_root)
					elseif tmp_node.get_value.three_way_comparison(to_delete) = 1 then -- tmp_node.get_value > to_delete
						tmp_node:= attached_node(tmp_node.get_left)
					else
						tmp_node:= attached_node(tmp_node.get_right)
					end
				end
			end

feature {GENERICTREE} --Subroutine to delete one explicit node in tree

		delete_node(node: NODE[G])
			local
				tmp_node: NODE[G]
				tmp_parent: NODE[G]
				tmp_value: G
			do
				if node.get_left = void and node.get_right = void then
--node is leaf
					if node.get_parent = void then
	--node is root
						root:= void
						empty:= true
					else
						tmp_parent:= attached_node(node.get_parent)
						if tmp_parent.get_value > node.get_value then
							tmp_parent.set_left(void)
						else
							tmp_parent.set_right(void)
						end
					end
				elseif node.get_left = void then
--node has only right child
					tmp_node:= attached_node(node.get_right)
					if node.get_parent = void then
	--node is root
						root:= tmp_node
						tmp_node.set_parent(void)
					else
	--node isn't root
						tmp_parent:= attached_node(node.get_parent)
						if tmp_parent.get_value > node.get_value then
							tmp_parent.set_left(tmp_node)
						else
							tmp_parent.set_right(tmp_node)
						end
					end
				elseif node.get_right = void then
--node has only left child
					tmp_node:= attached_node(node.get_left)
					if node.get_parent = void then
	--node is root
						root:= tmp_node
						tmp_node.set_parent (void)
					else
	--node isn't root
						tmp_parent:= attached_node(node.get_parent)
						if tmp_parent.get_value > node.get_value then
							tmp_parent.set_left(tmp_node)
						else
							tmp_parent.set_right(tmp_node)
						end
					end
				else
--node has two children
					from
						tmp_node:= attached_node(node.get_right)
					until
						tmp_node.get_left = void
					loop
						tmp_node:= attached_node(tmp_node.get_left)
					end

					tmp_value := tmp_node.get_value
					node.set_value(tmp_value)
					delete_node(tmp_node)
				end
			end



feature --check Attach

	attached_node(d_node: detachable NODE[G]): attached NODE[G]
					--returns an attached node
		do
			check attached d_node as a_node then
				Result:= a_node
			end
		end

end

