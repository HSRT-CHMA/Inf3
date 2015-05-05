note
	description: "Summary description for {SUM_PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SUM_PROBLEM

inherit
	MAIN_PROBLEM
		redefine
			solve
		end

create
	make

feature {GPS} -- Initialization

	make(used_tree : BINARYTREE)
		do
			print("New SUM_Problem")
			create sum_s.make
			set_start_value(used_tree)
			solve
		end


feature -- Access

	sum_s : detachable SUM_SOLUTION
	-- The Sum_Problem knows a Sum_Solution-Object, which recives the solution_value
	start_value : BINARYTREE
	-- The Tree on which the operations are performed
	solution_value : INTEGER

feature -- Getter for Solution

	get_solution : detachable SUM_SOLUTION
	do
		if attached sum_s as checked_sum_s then
			Result := checked_sum_s
		end
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
			--sum_s.set_solution_value(max(checked_root))
			--get_solution.set_solution_values(sum(checked_root))
			solution_value := sum(checked_root)
			print("Sum-Problem : " + solution_value.out)
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
