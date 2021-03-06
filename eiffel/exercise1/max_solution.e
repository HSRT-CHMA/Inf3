note
	description: "Summary description for {MAX_SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	MAX_SOLUTION

inherit
	SOLUTION
		redefine set_solution_value end
		--- redefine clause lists features that are redefine/"overwritten" in this class


create
	make

feature {NONE} -- Initialization

	make
			-- Initialization for `Current'.
		do
			-- print("A SOLUTION-Object has been created")
		end

feature --Access

	solution_value : INTEGER
	-- contains the value of the solution

feature{GPS} -- Getter for solution_value; only exported to GPS

	get_solution_value : INTEGER
	do
		Result := solution_value
		ensure
			correct_result : Result = solution_value
	end

feature{MAX_PROBLEM} -- Setter for solution_value, only exported to valid Problem-Class

	set_solution_value(new_solution_value : INTEGER)
	do
		solution_value := new_solution_value
		ensure then
			correct_value : solution_value = new_solution_value
	end

invariant
	valid_solution_value : solution_value.abs >= 0


end
