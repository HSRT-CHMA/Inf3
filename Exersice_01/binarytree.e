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
			create node.make(tree_value)

		end


feature --Variables

	-- The root-Node of the tree
	root : NODE
	-- Node-Object for Testing
	node : NODE

feature --Getter root
	get_root : NODE
	do
		Result := root --Result is built-in and used instead of "return"
	end

feature --Function to insert a value in tree

	insert(new_node : NODE ; new_value : INTEGER)
		do
			if then

			end
		end







end
