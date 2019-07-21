"""
!/usr/bin/python
-*- coding: utf-8 -*-
    members:
        put_text_to_video
"""
import cv2
import json
import os

from config import Config


def put_text_to_video(video: str, json_file: str, texts: dict):
    """
    :param video: the video path
    :param json_file: the json file that is created by tool VideoTargetMark
    :param texts the text which will be put to the video
        {'target_id': text, ... }
    """
    # open video file
    video_cap = cv2.VideoCapture(video)

    # open json file
    with open(json_file, 'r', encoding='UTF-8') as f:
        json_data = json.load(f)

    # get all target information
    targets = json_data['notation']

    # a list to save the frame that has been put text
    frame_with_text = []
    for target in targets:
        # read frame from video
        having, frame = video_cap.read()
        # get target id, position and put text
        for each in target['target_track']:
            text = texts[each['id']]
            pos = (each['region']['column'], each['region']['row'])
            # img, text, position, font, font_size, font_color, font_thickness
            cv2.putText(frame, text, pos, cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 255), 1)
        frame_with_text.append(frame)

    # get absolute path of video
    video_abs_path = os.path.abspath(video).split('.')
    # create video file name
    video_with_text = '{}_text.{}'.format(video_abs_path[0], video_abs_path[1])
    # get video width, height and fps
    width, height = json_data['frame_width'], json_data['frame_height']
    fps = json_data['fps']

    # file_name, video coding, fps, (video width, height)
    video_writer = cv2.VideoWriter(video_with_text, cv2.VideoWriter_fourcc(*'MP42'), fps, (width, height))
    for frame_text in frame_with_text:
        video_writer.write(frame_text)
    # close writer
    video_writer.release()


if __name__ == '__main__':
    put_text_to_video(Config.VIDEO, Config.JSON, Config.TEXTS)
