import tensorflow as tf

state=tf.Variable(0,name='counter')
one=tf.constant(1)

new_value=tf.add(state,one)
update=tf.assign(state,new_value)

init=tf.initialize_all_variables() # must have if variables defined.

with tf.Session() as sess:
	sess.run(init)

	for _ in range(3):
		sess.run(update)
		print (sess.run(state))
