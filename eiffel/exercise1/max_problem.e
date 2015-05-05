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
			print("New MAX-Problem")
			create max_s.make
		end

feature --Access

	max_s : detachable MAX_SOLUTION

feature -- Class redefines inherited method solve

	solve
	do
		if attached used_tree.get_root as checked_root then
			max_s.set_solution_value(max(checked_root))
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
			used_node.get_left = Void
		loop
			if attached used_node.get_right as checked_right then
				used_node := checked_right
			end
		end
		Result := used_node.get_value
	end

end
