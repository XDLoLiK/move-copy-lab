# Move/Copy Semantics

## Copy Semantics
When talking about copy semantics, it is better to differentiate
between shallow copying and deep copying.

### Shallow Copying
Shallow copying is the type of copying that compiler does by default.
When talking about classes it only involves copying of the values of
the corresponding fields. It is, indeed, fast but rather unsafe as well.
Underlying dangers involve the lack of data safety and possibility of
memory use after free.

### Deep Copying
Deep copying involves full copying of the data. Simlpy: slow but reliable.

## Move Semantics
C++ move constructors use so-called rvalue references. Rvalue references
are basically references to the objects which are soon to be destroyed.
These temporary objects are never to be used by the user, thus they
can serve us as a trash can where we store all the useless data.
In move constructors we can always use shallow copying. That is why
move constructors are usually a better choice when talking about speed.

Let's now consider a simple algorithm of swapping two integers
(DemoInts actually).

![Test Program](https://github.com/XDLoLiK/demo-int/blob/master/lab_data/move_disabled.png)

As we can see here, with move constructors disabled we get a rather
upleasing picture. Copy counter as well as the number of tmp
variables reaches 11. Pretty expensive as for 4 lines of code, isn't it?

But now take a look at what we get when we allow move semantics.

![Move Semantics Enabled](https://github.com/XDLoLiK/demo-int/blob/master/lab_data/move_enabled.png)

What we see now is a dramatic drop in amount of copies (more than twice as good!).
Although, the amount of tmps stays on the same level.

We now can improve the algorithm by passing the argument by
reference rather than by value.

![Passing Arguments By Reference](https://github.com/XDLoLiK/demo-int/blob/master/lab_data/reference_optimization.png)

What we get now is 0 copies and only 7 temporary variables. But
there's always a roow for improvement! Let's now use direct assignment
operations instead of arithmetics.

![Assignment Operation](https://github.com/XDLoLiK/demo-int/blob/master/lab_data/assignement_optimization.png)

Great job! At the end we geet zero copies and a couple of temporary objects.

To summarize, the copy constructor makes a deep copy, because the source
must remain untouched. The move constructor, on the other hand, can just copy
the pointer and then set the pointer in the source to null. It is okay to "nullify"
the source object in this manner, because the client has no way of inspecting the object again.
