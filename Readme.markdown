
# Relation C Library

## Description

Relation is is a Relational Algebra made in C language.

### Based on Arel, Sequel and DataMapper.

## Why I'm creating this library:

* It was a <b>motivation</b> to learn <b>C language</b> and how create Wrappers to other languages, like Ruby and Python

## Actual Results


### Ruby Wrapper

     users = Relation::Table('users')
     
     users.select('*').to_sql
     => "SELECT * FROM users"
     
     users.select('*').limit(10).to_sql
     => "SELECT * FROM users LIMIT 10"

## Benchmarks


Some <b>LITTLE</b> benchmarking about the actual results:

<a href="https://gist.github.com/705274">https://gist.github.com/705274</a>

