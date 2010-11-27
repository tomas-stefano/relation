bench_dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH.unshift(File.join( bench_dir, '..', 'lib'))

require 'benchmark'
require 'relation'

@table = Relation::Table.new('users')

def simple_query!
  @table.select('*').limit(1).to_sql # SELECT * from users LIMIT 1
end

def with_where!
  @table.select('*').limit(1).where("login = 'tomas'").to_sql # SELECT * from users WHERE login = 'tomas' LIMIT 1
end

def with_order_and_where!
  @table.select('*').limit(10).where("login = 'tomas'").order('login').to_sql # SELECT * from users WHERE login = 'tomas' ORDER BY login LIMIT 10
end

# Little benchmarking (I'll begin to start more seriously benchs when the wrapper is growing )
Benchmark.benchmark do |x|
  x.report("10.000 Queries    ") do
    10_000.times do
      simple_query!
    end
  end
  x.report("100.000 Queries   ") do
    100_000.times do
      simple_query!
    end
  end
  x.report("1.000.000 Queries ") do
    1_000_000.times do
      simple_query!
    end
  end
end

