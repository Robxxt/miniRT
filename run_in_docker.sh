# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_in_docker.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 09:38:43 by rdragan           #+#    #+#              #
#    Updated: 2023/11/05 11:01:15 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ -z "$(docker images | grep "mini_rt_env"| head -1)" ]; then
	docker build -t "mini_rt_env" .
	docker run -it -v $PWD:/app -w /app mini_rt_env
else
	docker run -it -v $PWD:/app -w /app mini_rt_env
fi
docker rm $(docker ps -a | grep mini_rt_env | head -1 | awk '{print $1}')
