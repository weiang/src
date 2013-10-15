module M
	def say
		p "Hello world from M"
	end
end

module N
	def say 
		p "Hello world from N"
	end
end

class Test
	include M
	include N
#	def say
#		p "Hello world from Test"
#		super
#		p "Hello world after Test"
#	end
end

test = Test.new
test.say

module T
	class L
		def say 
			p "hello"
		end
	end
end

a = T::L.new
a.say

