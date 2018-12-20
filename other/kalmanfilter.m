function y = kalmanfilter(z)
	dt = 1;
	% Initialize state transition matrix
	A = [ 	1  0 dt  0  0  0		% [x]
			0  1  0 dt  0  0		% [y]
			0  0  1  0 dt  0		% [Vx]
			0  0  0  1  0 dt		% [Vy]
			0  0  0  0  1  0		% [Ax]
			0  0  0  0  0  1];		% [Ay]
	H = [   1  0  0  0  0  0 		% Init ...
	        0  1  0  0  0  0]; 		% measurements;
	Q = eye(6);
	R = 1000 * eye(2);
	persistent x_est p_est			% Init state cond
	if isempty(x_est)
		x_est = zeros(6, 1);		% x_est = [x, y, Vx, Vy, Ax, Ay]'
		p_est = zeros(6, 6);
	end

	x_prd = A * x_est;				% Predicted state and covariance
	p_prd = A * p_est * A' + Q;

	S = H * p_prd' * H' + R;		% Estimation
	B = H * P_prd';
	klm_gain = (S \ B)';

	% Estimated state and covariance
	x_est = x_prd + klm_gain * (z - H * x_prd);
	p_est = p_prd - klm_gain * H * p_prd;
	y = H * x_est;					% Compute the estimated measurements 
end									% of the function

