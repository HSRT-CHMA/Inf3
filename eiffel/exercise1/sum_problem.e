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

create
	make

feature {GPS} -- Initialization

	make(used_tree : BINARYTREE)
			-- Initialization for `Current'.
		do
			print("New SUM_Problem")
		end


feature -- Access

	sum_s : detachable SUM_SOLUTION

feature -- Public sum-Method to find the sum of a given tree

	solve
	do
		--if attached current.get_root as check_root then
			--Result := solve_sum(check_root)
			--Result := sum(check_root)
		--end

		if attached used_tree.get_root as checked_root then
			sum_s.set_solution_value(max(checked_root))
		end
	end

feature{NONE} -- Sum of the tree

	sum(used_node : detachable NODE) : INTEGER
	do
		if used_node = Void then
			Result := 0
		else
			Result := used_node.get_value + sum_rec(used_node.get_left) + sum_rec(used_node.get_right)
		end
	end

end
