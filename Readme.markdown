
# Relation C Library

## Description

Relation is is a Relational Algebra made in C language.

### Based on Arel, Sequel and DataMapper.

## Why I'm creating this library:

* I want to learn <b>C language</b> and how create Wrappers to other languages, like Ruby and Python! (and this is a better way to do it! I think)

## Actual Results


### Ruby Wrapper

     users = Relation::Table('users')
     
     users.select('*').to_sql
     => "SELECT * FROM users"
     
     users.select('*').limit(10).to_sql
     => "SELECT * FROM users LIMIT 10"

     users.select('name').where("name = 'tomas'").to_sql
     => "SELECT name FROM users WHERE name = 'tomas'"

     users.select('name').where("name = 'tomas'").group('name').to_sql
     => "SELECT name FROM users WHERE name = 'tomas' GROUP BY name"

     users.select('name').where("name = 'tomas'").group('name').having('age = 21').to_sql
     => "SELECT name FROM users WHERE name = 'tomas' GROUP BY name HAVING age = 21"

     users.select('login').where("login = 'tomas'").group('name').having('age = 21').order("login").to_sql
     => "SELECT login FROM users WHERE login = 'tomas' GROUP BY name HAVING age = 21 ORDER BY login"

     users.select('login').where("login = 'tomas'").group('name').order("login").offset(100).to_sql
     => "SELECT login FROM users WHERE login = 'tomas' GROUP BY name ORDER BY login OFFSET 100"

## Benchmarks

### Benchmarks Ruby Wrapper

Some <b>LITTLE</b> benchmarking about the actual results:

<a href="https://gist.github.com/705274">https://gist.github.com/705274</a>

### Running Tests

Just type in the root folder:

   rake test

### Pull Request

- Don't forget about testing! =-)