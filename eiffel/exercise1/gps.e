note
	description: "Summary description for {GPS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	GPS

create
	make

feature{NONE} -- Initialization / Constructor ; receives the tree on which operations will be performed an initialise two Problem-Objects

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

feature -- Getter for the max_value of the Max_Solution-Object, which inherits SOLUTION,thereby redefines the get_solution and get_solution_value-Method

	get_max : INTEGER
	do
		if attached max_prob.get_solution as checked_solution then
			Result := checked_solution.get_solution_value
		end
		ensure
			result_is_valid : Result.abs >= 0
	end

feature -- Getter for the sum_value of the Sum_Solution-Object, which inherits SOLUTION,thereby redefines the get_solution and get_solution-value-Method

	get_sum : INTEGER
	do
		if attached sum_prob.get_solution as checked_solution then
			Result := checked_solution.get_solution_value
		end
		ensure
			result_is_valid : Result.abs >= 0
	end

invariant
	valid_sum_problem : sum_prob /= Void
	valid_max_problem : max_prob /= Void

end
