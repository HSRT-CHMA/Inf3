note
	description: "Summary description for {GPS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	GPS

create
	make

feature{NONE} -- Initialization

	make(used_tree : BINARYTREE)
			-- Initialization for `Current'.
		do
			create max_prob.make(used_tree)
			create sum_prob.make(used_tree)

		end

feature --Access

	max_prob : MAX_PROBLEM
	-- GPS creates a MAX_PROBLEM Object with given tree
	sum_prob : SUM_PROBLEM
	-- GPS creates a SUM_PROBLEM Object with given tree
end
