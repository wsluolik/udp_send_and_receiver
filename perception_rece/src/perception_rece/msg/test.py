#!/usr/bin/env python 
#-*-coding:utf-8 -*-
import rospy
from PerceptionMsg.msg import PMsg

     
def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %d", data.id)
    
def listener():
 
    rospy.init_node('demo', anonymous=True)
 
    rospy.Subscriber("//rs_percept_result",PMsg, callback)
 
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()
 
if __name__ == '__main__':
    listener()

