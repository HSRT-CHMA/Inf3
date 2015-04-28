note
	description: "Summary description for {BINARYTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BINARYTREE

create -- List of creation methods
	make

feature {NONE} -- Initialization

	make(tree_value : INTEGER)
			-- Initialization for `Current'.
		do
			print("New BinaryTree with value : " + tree_value.out)
			create node.make(tree_value , Void)

		end


feature --Variables

	-- The root-Node of the tree; can be Void (detachable)
	root : detachable NODE
	-- Node-Object for Testing; can be Void
	node : detachable NODE
	-- Booolean to be used in has(int)-Function
	b : BOOLEAN

feature --Getter root
	get_root : NODE
	do
		Result := root --Result is built-in and used instead of "return"
	end

feature --Procedure to insert a value in tree

	insert_Rek(new_value : INTEGER; new_node : NODE)
		Local
				next_node : detachable NODE
		do
			if new_node.get_value >= new_value then
				if attached new_node.get_right as checked_node then
					next_node.make(new_value, new_node)
					checked_node.set_right (next_node)
				else
					insert_Rek(new_value, new_node.get_right)
				end
			else
				if new_node.get_left = Void then
					new_node.set_left (new_node.make(new_value, new_node))
				else
					insert_Rek(new_value, new_node.get_left)
				end
			end
		end

--feature -- Function to insert a value in a tree

	--insert(new_value : INTEGER)
		--do
			--ensure
			--Current.get_root /= Void
			--Result := insert_Rek(new_value , Current.get_root)
		--end





feature --Function to check the existence of a value in tree

	has(value : INTEGER) : BOOLEAN
		do
			Result := b
		end


feature --Procedure to delete a value in the tree

	delete(value : INTEGER)
		do
			ensure has(value) = false
		end


end
