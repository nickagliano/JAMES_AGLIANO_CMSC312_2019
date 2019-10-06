
// iterate through a queue without messing up order
int highestPriority = INT_MAX;
size_t size = rq.size();
while (size-- > 0) {
	int x = rq.front();
	rq.pop();
	rq.push(x);
	if (x < highestPriority)
	highestPriority = x;
}
