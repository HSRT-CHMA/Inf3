note
	description: "Summary description for {MAIN_PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	MAIN_PROBLEM
	-- The class is "abstract" and should offer methods for child-problem-classes

feature -- Problem has the "abstract" / deferred solve-Method ; every child should redefine this method

	solve
	do --deferred
	end

end
