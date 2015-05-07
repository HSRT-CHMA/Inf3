note
	description: "Summary description for {MAX_PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	MAX_PROBLEM

inherit
	MAIN_PROBLEM
		redefine solve end
		--- redefine clause lists features that are redefine/"overwritten" in this class

create
	make

feature {GPS} -- Initialization; creates a corresponding SOLUTION-Object, receives tree and sets this as start value, operates the solve - Method

	make(used_tree : BINARYTREE)
			-- Initialization for `Current'.
		do
			create max_s.make
			set_start_value(used_tree)
			solve

		end

feature -- Access

	max_s : detachable MAX_SOLUTION
	-- The Sum_Problem knows a Sum_Solution-Object, which recives the solution_value
	start_value : BINARYTREE
	-- The Tree on which the operations are performed

feature -- Getter for Solution-Object of this class

	get_solution : detachable MAX_SOLUTION
	do
		Result := max_s
		ensure
			valid_result : Result = max_s
	end

feature -- public Getter for start_value

	get_start_value : BINARYTREE
	do
		Result := start_value
		ensure
			valid_result : Result = start_value
	end

feature{NONE} --private Setter for start_value

	set_start_value(used_tree : BINARYTREE)
	do
		start_value := used_tree
		ensure
			valid_start_value : start_value = used_tree
	end


feature -- Class redefines inherited method solve, reedirects to max-method

	solve
	do
		if attached start_value.get_root as checked_root then
			if attached get_solution as checked_solution then
				checked_solution.set_solution_value (max(checked_root))
			end
		end
	end


feature{NONE} -- Method to find Max value of the tree with a while-loop-construcktion , "private"

	max(start : NODE) : INTEGER
	require
		valid_start : start /= Void
	Local
		used_node : NODE
	do
		from
			used_node := start
		until
			used_node.get_right = Void
		loop
			if attached used_node.get_right as checked_right then
				used_node := checked_right
			end
		end
		Result := used_node.get_value
		ensure
			valid_result : Result.abs >= 0
			max_is_in_tree : start_value.has (Result)
	end

end
