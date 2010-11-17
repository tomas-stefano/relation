bench_dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH.unshift(File.join( bench_dir, '..', 'lib'))

require 'benchmark'
require 'relation'

@creation_number = 1_000_000
report = "#{@creation_number} times"

Benchmark.benchmark do |x|
  x.report("Create Relation Table #{report}\n") do
    @creation_number.times do
      Relation::Table.new('users')
    end
  end
  puts
  x.report("Create and access the table name #{report}\n") do
    @creation_number.times do
      table = Relation::Table.new('users')
      table.name
    end
  end
  # x.report("Create a SELECT * FROM users #{report}\n") do
  #   @creation_number.times do
  #     table = Arel::Table.new(:users)
  #     table.take("*").to_sql
  #   end
  # end
  puts
end