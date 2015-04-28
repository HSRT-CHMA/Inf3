note
	description : "Exersice_01 application root class"
	date        : "$Date$"
	revision    : "$Revision$"

class
	APPLICATION

inherit
	ARGUMENTS

create
	make

feature {NONE} -- Initialization

	make
			-- Run application.
		do
			--| Add your code here
			print ("Hello %N")
			create b.make(number)
			b.insert_Rek (number + 12, b.get_root)
		end

feature --Access

	-- A Node for Testing; can be Void
	n : detachable NODE
	-- A binaryTree for Testing
	b : detachable BINARYTREE
	-- An int Value for Testing
	number : INTEGER

end
