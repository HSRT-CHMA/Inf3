note
	description: "Summary description for {SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SOLUTION

--feature -- Setter for the solution_value,

	--set_solution_value(new_value : INTEGER)
	--do --deferred
		--solution_value := new_value
	--end

--feature -- the value that contains the solution of the given object

	--solution_value : INTEGER

end
