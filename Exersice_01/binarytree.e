note
	description: "Summary description for {BINARYTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BINARYTREE

create
	make

feature {NONE} -- Initialization

	make
			-- Initialization for `Current'.
		do
			print("New BinaryTree")

		end


feature --Variables

	-- The root-Node of the tree
	root : NODE

feature --Getter root
	get_root : NODE
	do
		Result := root
	end

end
