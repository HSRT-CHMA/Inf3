note
	description: "Summary description for {SUM_PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SUM_PROBLEM

inherit
	MAIN_PROBLEM
		redefine solve end
		--- redefine clause lists features that are redefine/"overwritten" in this class

create
	make

feature {GPS} -- Initialization

	make(used_tree : BINARYTREE)
		do
			create sum_s.make
			set_start_value(used_tree)
			solve
		end


feature -- Access

	sum_s : detachable SUM_SOLUTION
	-- The Sum_Problem knows a Sum_Solution-Object, which recives the solution_value
	start_value : BINARYTREE
	-- The Tree on which the operations are performed

feature -- Getter for Solution

	get_solution : detachable SUM_SOLUTION
	do
			Result := sum_s
	end

feature -- public Getter for start_value

	get_start_value : BINARYTREE
	do
		Result := start_value
	end

feature{NONE} --private Setter for start_value

	set_start_value(used_tree : BINARYTREE)
	do
		start_value := used_tree
	end

feature -- Public sum-Method to find the sum of a given tree

	solve
	do
		if attached start_value.get_root as checked_root then
			if attached get_solution as checked_solution then
				checked_solution.set_solution_value (sum(checked_root))
			end
		end
	end

feature{NONE} -- Sum of the tree

	sum(used_node : detachable NODE) : INTEGER
	do
		if used_node = Void then
			Result := 0
		else
			Result := used_node.get_value + sum(used_node.get_left) + sum(used_node.get_right)
		end
	end

end
