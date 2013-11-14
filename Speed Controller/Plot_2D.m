
plot(ans(1,1:25201), ans(2,1:25201)); figure(gcf);grid('on'); xlabel('time (s)'); ylabel('desired velocity (km/h)')
plot(ans(1,1:25201), ans(3,1:25201)); figure(gcf);grid('on'); xlabel('time (s)'); ylabel('vehicle velocity (km/h)')
plot(ans(1,1:25201), ans(4,1:25201)); figure(gcf);grid('on'); xlabel('time (s)'); ylabel('local verdict 1')
plot(ans(1,1:25201), ans(5,1:25201)); figure(gcf);grid('on'); xlabel('time (s)'); ylabel('local verdict 2')
