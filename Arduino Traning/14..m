% This MATLAB script shows how to use MATLAB to map your surroundings using 
% an Arduino and an ultrasonic sensor.

% Copyright 2016 The MathWorks, Inc
clear all;
%% Create an Arduino object with the necessary add-ons.
a = arduino('COM4', 'Uno', 'Libraries', {'Ultrasonic', 'Servo'});

%% Create an ultrasonic sensor object with trigger pin D12 and echo pin D13.
%  Create a servo object for the servo connected to pin D3. 
sensor = ultrasonic(a, 'D12', 'D13');
servo_motor = servo(a, 'D3');

%% Rotate the servo motor from 0 to 180 degrees.
%  Every time the motor rotates, determine the distance of any obstacles
%  via the bounceback time of the ultrasonic ping. Take two measurements
%  and average them for accuracy. Record the angle and the distance (in cm)
i = 1;
table = zeros(180,2);
for theta = 0 : 1/180 : 1
    writePosition(servo_motor, theta);
    dist1 = readDistance(sensor);
    pause(.04);
    dist2 = readDistance(sensor);
    dist = (dist1+dist2)/2;
    table(i,1) = (i-1);
    table(i,2) = round(dist * 100,2);
    i = i + 1;
end
%  Rotate the servo motor from 180 to 0 degrees. Replace the values in the
%  table with the average of the clockwise and counterclockwise scans to
%  improve the accuracy of the map.
j = 1; 
for theta = 1 : -1/180 : 0
    writePosition(servo_motor, theta);
    dist1 = readDistance(sensor);
    pause(.04);
    dist2 = readDistance(sensor);
    dist = (dist1+dist2)/2;
    table(i-j,2) = (table(i-j,2) + round(dist * 100,2))/2;
    j = j + 1;
end

%% Make a polar plot of the distance data to display the map. 
%  Limit the theta values to be between 0 and 180 because the map is only
%  for obstacles in front of the servo. 
polarplot (table(:,1)*pi/180, table (:,2));
title('Map of the Environment');
thetalim([0 180]);
grid on;