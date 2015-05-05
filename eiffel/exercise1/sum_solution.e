note
	description: "Summary description for {SUM_SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SUM_SOLUTION

inherit
	SOLUTION
		--redefine solution_value end

create
	make

feature {NONE} -- Initialization

	make
			-- Initialization for `Current'.
		do

		end

feature -- Acces

	solution_value : INTEGER
	-- contains the value of the solution

feature{GPS} -- Getter for solution_value (public but not sure about that)

	get_solution_value : INTEGER
	do
		Result := solution_value
	end

feature{SUM_PROBLEM} -- Setter for solution_value, only esported to valid Problem-Class

	set_solution_value(new_solution_value : INTEGER)
	do
		solution_value := new_solution_value
	end

end
