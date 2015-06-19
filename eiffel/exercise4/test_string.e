note
	description: "Summary description for {TEST_STRING}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	TEST_STRING

create
	make

feature --Access

	ran : RANDOMGENERATOR
	string_tree : BINARYTREE[STRING]
	index : INTEGER

feature -- Constructor
 	make(out_tree : BINARYTREE[STRING])
 	do
 		create ran.make
 		-- create is like new ; new RG Object
 		string_tree := out_tree
 	end


feature -- Inits the given tree
	tree_init(min : INTEGER ; max : INTEGER ; element_amount : INTEGER )
	do
		if min > max then
			print("Minimum value must not be greater than the maximum value!")
		end

		if element_amount < 1 then
			print ("The Number of Items must not be smaller then 0!")
		else
			from
				index := 0
			until
				index = element_amount
			loop
				string_tree.insert (ran.get_ra_string(min, max))
				index := index + 1
			end
		end

	end

feature
	output
	do
		print ("Greater than 3 : ")
		print ("Contains 's' :")
	end


end
