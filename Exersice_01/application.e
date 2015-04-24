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
			print ("Hello Eiffel World!%NHappy Birthday Georgi!!!!!!!!! %N")
			create n.make(number)
			print ("%N")
			create b.make(number)
		end

feature --Access
	n : NODE
	b : BINARYTREE
	number : INTEGER = 677

end
