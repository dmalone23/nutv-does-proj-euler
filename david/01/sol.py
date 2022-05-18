#!/usr/bin/env python3

sum(list(filter(lambda x: (x % 3 == 0) or (x % 5 == 0),[x for x in range(1,1000)])))
