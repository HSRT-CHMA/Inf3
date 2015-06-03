note
	description: "Summary description for {AVLTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	AVLTREE[G->COMPARABLE]

inherit
	-- BINARYTREE  Vererbung überprüfen
	GENERIC_TREE[G]
	redefine insert, delete, has end

create
	make

feature {NONE} -- Initialization / Constructor ; gets the value that serves as root-value

	make(tree_value : G)
		do
			print("%N A new AVL Tree has been created")
			create root.make(tree_value, Void)
		end

feature
	insert(new_value : G)
	do
		Precursor(new_value)
	end


feature
	delete(new_value : G)
	do
		Precursor(new_value)
	end

feature
	has(new_value : G): BOOLEAN
	do
		Result := Precursor(new_value)
	end

end
