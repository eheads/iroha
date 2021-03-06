/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.
http://soramitsu.co.jp

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef CORE_DOMAIN_TRANSFER_HPP_
#define CORE_DOMAIN_TRANSFER_HPP_

#include <model/objects/domain.hpp>
#include <model/objects/asset.hpp>
#include <model/objects/message.hpp>

#include <string>
#include <iostream>

namespace command {

    template<typename T>
    class Transfer : public T {

    public:

        std::string senderPublicKey;
        std::string receiverPublicKey;

        template<typename... Args>
        explicit Transfer(
                std::string&& sender,
                std::string&& receiver,
                Args&&... args
        ):
                T(std::forward<Args>(args)...),
                senderPublicKey(std::move(sender)),
                receiverPublicKey(std::move(receiver))
        {}

        auto getCommandName() const {
            return "Transfer";
        }

        void execution();

    };  // namespace command
};
#endif  // CORE_DOMAIN_TRANSACTIONS_TRANSFERTRANSACTION_HPP_

