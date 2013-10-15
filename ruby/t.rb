class Array
	def iterate!(&code)
		self.each_with_index do |n, i|
			self[i] = code.call(n)
		end
	end
end

array = [1, 2, 3, 4]

square = Proc.new do |n|
	n ** 2
end

array.iterate!(&square)

p array

def callbacks(procs)
	procs[:starting].call
	puts "Sting going"
	procs[:finishing].call
end
callbacks(:starting => Proc.new { puts "Staring "}, 
		  :finishing => Proc.new {puts "Finishing"})

