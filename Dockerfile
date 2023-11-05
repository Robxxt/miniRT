# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 09:32:14 by rdragan           #+#    #+#              #
#    Updated: 2023/11/05 10:12:52 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest
COPY . /app
RUN apk add clang g++ make valgrind
CMD cd app && make re && ./miniRT