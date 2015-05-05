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

feature -- Getter for the max_value of the Max_Solution-Object, which inherits SOLUTION,thereby redefines the get_solution-Method

	get_max : INTEGER
	do
		if attached max_prob as check_max then
			--Result := check_max.get_solution.get_max_value
		end

	end

feature -- Getter for the sum_value of the Sum_Solution-Object, which inherits SOLUTION,thereby redefines the get_solution-Method

	get_sum : INTEGER
	do
		if attached sum_prob as check_sum then
			--Result := check_sum.get_solution.get_sum_value
		end
	end

end
