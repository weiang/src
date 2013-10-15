def proc_return 
	Proc.new {puts "Proc.new"}.call
	puts "Proc_return finished"
	return "Proc_finished"
end

def lambda_return 
	lambda { return "Lambda"}.call
	puts "In lamebda"
	return "lamebda_return method finished"
end

#proc_return
#lambda_return
puts proc_return
puts lambda_return


class Array 
	def iterate!(code)
		self.each_with_index do |n, i|
			self[i] = code.call(n)
		end
	end
end

def square(n)
	n ** 2
end

array = [1, 2, 3, 4]
array.iterate!(method(:square))
puts array.inspect
