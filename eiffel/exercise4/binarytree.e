note
	description: "Summary description for {BINARYTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BINARYTREE[G->COMPARABLE]	-- -> CONSTRAINT create make end]
	-- This class organises the binary tree and provides important methods

inherit
	GENERICTREE[G]
	redefine insert, delete, has end

create
	make

feature {NONE} -- Initialization / Constructor ; gets the value that serves as root-value

	make(tree_value : G)
		do
			print("%N A new Binary Tree with the Value: "+tree_value.out +" has been created")
			empty:= TRUE
			create root.make(tree_value, Void)
		end

feature
	insert(new_value : G)
		do
			Precursor(new_value)
		end


feature
	delete(value : G)
		do
			Precursor(value)
		end

feature
	has(to_delete : G): BOOLEAN
		do
			Result := Precursor(to_delete)
		end

end --End of class
