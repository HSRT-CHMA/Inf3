note
	description: "Summary description for {MAIN_PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred
	class
	MAIN_PROBLEM

feature -- Problem has the "abstract" / deferred solve-Method ; every child should redefine this method

	solve
	do --deferred
	end

end
