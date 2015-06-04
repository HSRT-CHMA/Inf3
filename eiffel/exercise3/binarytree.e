note
	description: "Summary description for {BINARYTREE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BINARYTREE[G->COMPARABLE]	-- -> CONSTRAINT create make end]
	-- This class organises the binary tree and provides important methods

	-- G erbt von ANY, Methoden von ANY nachschlagen und benutzen
	-- z.B: is_equal anstatt =
	-- is_less , is_greater

inherit
	GENERICTREE[G]
	redefine insert, delete, has end

create
	make

feature {NONE} -- Initialization / Constructor ; gets the value that serves as root-value

	make(tree_value : G)
		do
			print("%N A new Binary Tree with the Value: "+tree_value.out +"has been created")
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

end --End of class
