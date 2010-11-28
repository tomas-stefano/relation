
# Relation C Library

## Description

Relation is is a Relational Algebra made in C language.

## Based on Arel, Sequel and DataMapper.

## Why I'm creating this library:

* I want to learn <b>C language</b> and how create Wrappers to other languages, like Ruby and Python! (and this is a better way to do it! I think)

## Actual Results


### Ruby Wrapper

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

### Benchmarks Ruby Wrapper

Some <b>LITTLE</b> benchmarking about the actual results:

<a href="https://gist.github.com/705274">https://gist.github.com/705274</a>

### Running Tests

Just type in the root folder:

   rake test

### Pull Request

- Don't forget about testing! =-)
