note
	description: "Summary description for {TEST_REAL}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	TEST_DOUBLE

create
	make

feature --Access

	ran : RANDOMGENERATOR
	real_tree : BINARYTREE[DOUBLE]
	index : INTEGER

feature -- Constructor
 	make(out_tree : BINARYTREE[DOUBLE])
 	do
 		create ran.make
 		-- create is like new ; new RG Object
 		real_tree := out_tree
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
				real_tree.insert (ran.get_ra_double(min, max))
				index := index + 1
			end
		end

	end

feature
	output
	do
		print ("Smaller than 5 : ")
		print ("Negativ elements :")
		print ("Even elements : ")
	end


end
