# Test driven design in C++/Qt
This is an example repo for my talk [Consigli pratici per il Test Driven Development di applicazioni C++/Qt](https://www.youtube.com/watch?v=sTq3LTN1J9U)

## Repo organization

Inside `src` you will find example classes that I want to test.

The `tests/` directory differs depending on the branch:
* `master`: it shows how to test the `Gate` class that explicitly mentions a concrete class `Protocol`
* `multiple_mocks`: it shows a way to create multiple mock classes for `Protocol`