note
	description: "Summary description for {MAIN_PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	MAIN_PROBLEM

feature -- Getter for Solution

	get_solution : detachable SOLUTION
	do --deferred
		Result := present_solution
	end

feature -- Access

	present_solution : detachable SOLUTION


feature -- Problem has the "abstract" / deferred solve Method ; every child should redefine this method

	solve
	do -- deferred
	end

end
