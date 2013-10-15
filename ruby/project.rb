module Project
	attr_accessor :members
	def initialize
		@members = Array.new
	end

	def add(obj)
		@members.push(obj)
	end

	def remove
		@members.pop
	end
end

