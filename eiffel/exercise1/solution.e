note
	description: "Summary description for {SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SOLUTION

feature -- Solution has the "abstract" / deferred set_solution_value - method ; every child should redefine this method

	set_solution_value(solution_value : INTEGER)
	deferred
	end

end
