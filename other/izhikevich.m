% Parameter tuning for Regular Spiking
a = 0.02;
b = 0.2;
c = -65;
d = 8;

v = -65
u = b * v;

I_low = 0;
I_high = 10;

save_v = zeros(1,900);

for t = 1 : 900    % Simulation of 1000 ms
    % Auxiliary after-spike resetting
    if v >= 30 
        v = c;
        u = u + d;
    end

    if t >= 300 && t <= 600
        I = I_high;
    else
        I = I_low;
    end

    dv = 0.04 .* v .* v + 5 * v + 140 - u + I;
    du = a * (b*v - u);

    % Simple integration
    v = v + 0.5 * dv;   % step 0.5 ms
    v = v + 0.5 * dv;   % step 0.5 ms
    u = u + du;         % setp 1 ms
    save_v(t) = v;
end
plot(save_v);
ylabel('Voltage [mV]');
xlabel('Time [ms]');




