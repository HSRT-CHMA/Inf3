note
	description: "Summary description for {PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	PROBLEM

feature -- Getter for Solution

	get_solution : detachable SOLUTION
	do
		Result := solution
	end

feature --Access

	solution : detachable Solution


end
