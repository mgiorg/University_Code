#==================================================================================
#       Copyright (c) 2022 Northeastern University
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#          http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#==================================================================================

FROM ubuntu as buildenv

# Install dependencies
RUN mkdir -p /workspace
# This can be Rome, your preference
ENV TZ=America/New_York
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install -y wget build-essential git cmake libsctp-dev autoconf automake libtool bison flex libboost-all-dev tmux g++ python3 curl ninja-build openssh-server htop nano valgrind gdb

WORKDIR /workspace

# Install ns-3
RUN git clone https://gitlab.com/nsnam/ns-3-dev.git /workspace/ns3

WORKDIR /workspace/ns3

# Delete apt libraries to reduce the size of the final image
RUN rm -rf /var/lib/apt/lists/*

CMD ["/bin/bash"]