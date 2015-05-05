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

create
	make

feature {GPS} -- Initialization

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
	solution_value : INTEGER

feature -- Getter for Solution

	get_solution : detachable MAX_SOLUTION
	do
		Result := max_s
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


feature -- Class redefines inherited method solve

	solve
	do
		if attached start_value.get_root as checked_root then
			--max_s.set_solution_value(max(checked_root)) -- ergebniss von max() in Solution speichern
			-- Bisher nur so : ÄNDERN !!
			solution_value := max(checked_root)
		end

	end


feature{NONE} -- Method to find Max value of the tree, can only be used be this class

	max(start : NODE) : INTEGER
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
	end


end
