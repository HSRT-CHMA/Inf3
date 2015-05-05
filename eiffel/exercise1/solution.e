note
	description: "Summary description for {SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SOLUTION

feature --Access

	solution_value : INTEGER
	--The value of the Solution that can be read be GPS

feature -- Setter for the solution_value	

	set_solution_value(new_value : INTEGER)
	do
		solution_value := new_value
	end

end
