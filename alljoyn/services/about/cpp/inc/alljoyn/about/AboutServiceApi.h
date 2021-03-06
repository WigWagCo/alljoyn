/**
 * @file
 * Wrapper to encapsulate the AboutService with a singelton.
 */
/******************************************************************************
 * Copyright (c) 2013-2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#ifndef ABOUT_SERVICE_API_H
#define ABOUT_SERVICE_API_H

#include <qcc/Log.h>
#include <alljoyn/version.h>
#include <alljoyn/about/AboutService.h>
#include <alljoyn/about/PropertyStore.h>

namespace ajn {
namespace services {

/**
 *      AboutServiceApi  is wrapper class that encapsulates the AboutService with a Singelton.
 */
class AboutServiceApi : public AboutService {

  public:

    /**
     * GetInstance
     * @return AboutServiceApi created only once.
     */
    static AboutServiceApi* getInstance();
    /**
     * Init with  BusAttachment and PropertyStore only once.
     * After the first Init you can call getInstance to receive a proper instance of the class
     * @param bus
     * @param store
     */
    static void Init(ajn::BusAttachment& bus, PropertyStore& store);
    /**
     * Destroy the instance only once after finished
     */
    static void DestroyInstance();

  private:
    /**
     * Constructor
     * @param bus
     * @param store
     */
    AboutServiceApi(ajn::BusAttachment& bus, PropertyStore& store);
    /**
     * Desctructor
     */
    virtual ~AboutServiceApi();
    /**
     *  pointer to AboutServiceApi
     */
    static AboutServiceApi* m_instance;
    /**
     * pointer to BusAttachment
     */
    static BusAttachment* m_BusAttachment;
    /**
     * pointer to PropertyStore
     */
    static PropertyStore* m_PropertyStore;

};

}
}
#endif /* ABOUT_SERVICE_API_H */
