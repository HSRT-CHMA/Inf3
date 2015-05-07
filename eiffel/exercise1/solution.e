note
	description: "Summary description for {SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SOLUTION
	-- Abstract/deferred Super-Class to different SOLUTION-Objects

feature -- Solution has the "abstract" / deferred set_solution_value - method ; every child should redefine this method, which sets the value of the given solution

	set_solution_value(solution_value : INTEGER)
	deferred
	end

invariant
	--valid_solution_value : solution_value.abs >= 0

end
