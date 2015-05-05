note
	description: "Summary description for {MAIN_PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	MAIN_PROBLEM

feature -- Getter for Solution

	get_solution : detachable SOLUTION
	do -- deferred
		Result := present_solution
	end

feature -- Getter for start_value

	get_start_value : INTEGER
	do -- deferred
		Result := start_value
	end

feature -- Access

	present_solution : detachable SOLUTION
	-- The Solution-Object that the given Problem creates
	start_value : BINARYTREE
	-- The tree on which the operations are performed


feature -- Problem has the "abstract" / deferred solve Method ; every child should redefine this method

	solve
	deferred
	end

end
