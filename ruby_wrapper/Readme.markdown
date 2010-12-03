# Ruby Relation

A wrapper to Relation C Library.

In order to create:

    SELECT * FROM users

you create a Table object:

     users = Relation::Table('users')
     
     users.select('*').to_sql
     => "SELECT * FROM users"

#### A little more complexity

Using where operator:

     users.select('name').where("name = 'tomas'").to_sql
     => "SELECT name FROM users WHERE name = 'tomas'"

Using `LIMIT` or `OFFSET`:

     users.select('*').limit(10).to_sql
     => "SELECT * FROM users LIMIT 10"

     users.select('*').offset(10).to_sql
     => "SELECT * FROM users OFFSET 10"

Using `ORDER BY` as `#order`:

     users.select('*').order('name')
     => "SELECT * FROM users ORDER BY name"

Using `GROUP BY` as `#group` (like Arel):

	users.select('*').group('name')
	=> "SELECT * FROM users GROUP BY name"

Using `HAVING` as `#having`:

     users.select('name').group('name').having('age = 21').to_sql
     => "SELECT name FROM users GROUP BY name HAVING age = 21"

## Benchmarks

Some <b>LITTLE</b> benchmarking about the actual results:

<a href="https://gist.github.com/705274">https://gist.github.com/705274</a>

### Running Tests

Just type in the root folder:

   rake test

